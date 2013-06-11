# Create your views here.
import re
from django.template import RequestContext, loader
from django.http import HttpResponse
from django.shortcuts import render_to_response, get_object_or_404
import psware.common.ContextGenerator

def index(request):
	context=psware.common.ContextGenerator.generateContext(request)
	return render_to_response('common/index.html', RequestContext(request, context))
