import re
from django.template import RequestContext, loader
from django.http import HttpResponse
from django.shortcuts import render_to_response, get_object_or_404

# The User model defined in models.py
from psware.sub.models import *
from psware.pub.models import *
from psware.itransnet.models import *
from psware.itransnet.TrafficJamProcessor import *
from psware.sub.views import *
import psware.common.ContextGenerator

def valid(postData):
	if not 'selected' in postData:
		return False

	if not 'threshold' in postData:
		return False
	elif re.compile('[0-9]+').search(postData['threshold'])==None:
		return False

	return True
def index(request):
	selected = Selection.objects.all()
	selectedStr=''
	for a in selected:
		selectedStr=selectedStr+str(a.roadID)+','
	context = psware.common.ContextGenerator.generateContext(request)
	context['selected']=selectedStr
	return render_to_response('itransnet/index.html', RequestContext(request, context))
def trafficjamsub(request):
	if not valid(request.POST):
		return index(request)
	filter=None

	#Save selected road IDs
	selectionList=Selection.objects.all()
	if len(selectionList)>0:
		selectionList.delete()
	iter = re.compile('[0-9]+').finditer(request.POST['selected'])
	for match in iter:
		sub = Selection()
		sub.roadID = int(match.group())
		sub.save()

		if filter==None:
			filter='roadID=='+match.group()
		else:
			filter=filter+' ||\n\troadID=='+match.group()

	#Save threshold
	jamList=TrafficJam.objects.all()
	if len(jamList)>0:
		jamList.delete()
	jamList.delete()
	m = re.compile('[0-9]+').search(request.POST['threshold'])
	tj = TrafficJam()
	tj.threshold=int(m.group())
	tj.save()

	#Save subscription
	jamEvent = TrafficJamTemplate()
	jamEvent.where=filter
	saveSub(jamEvent.generateEDL())
	
	context = psware.common.ContextGenerator.generateContext(request)
	context['selected']=request.POST['selected']
	return render_to_response('itransnet/index.html', RequestContext(request, context))
def trafficjampub(request):
	detector=TrafficJamDetector()

	#Add cars
	for instance in EventInstance.objects.all():
		if instance.subID.eventName!='TrafficJam':
			continue
		car = CarEvent()
		attrList = EventInstanceAttribute.objects.filter(instanceID__exact=instance)
		for attr in attrList:
			if attr.attributeID.attributeName=='id':
				car.carID=attr.value
			elif attr.attributeID.attributeName=='roadID':
				car.roadID=attr.value
			elif attr.attributeID.attributeName=='posID':
				car.posID=attr.value
			elif attr.attributeID.attributeName=='status':
				car.status=attr.value
		detector.carList.append(car)

	#Add threshold
	jam = TrafficJam.objects.get()
	detector.threshold=jam.threshold

	#Add subscriptions
	for sub in Selection.objects.all():
		detector.subList.append(sub.roadID)

	return HttpResponse(detector.getPub())
def test(request):
	return render_to_response('itransnet/test.html', RequestContext(request, {}))
