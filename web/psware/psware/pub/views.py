# Create your views here.
from django.template import RequestContext, loader
from psware.pub.models import *
from django.http import HttpResponse
from django.shortcuts import render_to_response, get_object_or_404
import datetime
import psware.common.ContextGenerator

def eventPub(request):
	allEvents = EventInstance.objects.all().order_by('-pubTime')[0:20]
	context = psware.common.ContextGenerator.generateContext(request)
	context['events']=allEvents
	return render_to_response('pub/eventPub.html', RequestContext(request, context))
def detail(request, instance_id):
	try:
		instance = EventInstance.objects.get(pk=instance_id)
		attrs = EventInstanceAttribute.objects.filter(instanceID__exact=instance)
		context = psware.common.ContextGenerator.generateContext(request)
		context['instance']=instance
		context['attributes']=attrs
		return render_to_response('pub/detail.html', context)
	except EventInstance.DoesNotExist:
		raise Http404
	
