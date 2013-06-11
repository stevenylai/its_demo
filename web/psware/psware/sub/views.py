# Create your views here.
from django.template import RequestContext, loader
from psware.sub.models import Subscription
from django.http import HttpResponse
from django.shortcuts import render_to_response, get_object_or_404
import datetime
import psware.common.ContextGenerator

def saveSub(subStr):
	subList = Subscription.objects.all()
	if len(subList)>0:
		sub = subList[0]
	else:
		sub = Subscription()
		sub.version=1
	sub.sub=subStr
	sub.subTime=datetime.datetime.now()
	sub.version=sub.version+1
	sub.save()
	return sub
def eventDef(request):
	if 'sub' in request.POST:
		sub = request.POST['sub']
		saveSub(sub)
	else:
		sub=''
		subList = Subscription.objects.all()
		if len(subList)>0:
			sub=subList[0].sub

	context = psware.common.ContextGenerator.generateContext(request)
	context['sub']=sub
	return render_to_response('sub/eventDef.html', RequestContext(request, context))
