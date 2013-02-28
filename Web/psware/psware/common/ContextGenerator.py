import re
import psware.settings
def isInFacebook(request):
	for k,v in request.GET.items():
		if re.compile('fb_sig').search(k)!=None:
			return True
	return False
def generateContext(request):
	context={}
	context['URL_ROOT']=psware.settings.URL_ROOT
	if isInFacebook(request):
		context['IN_FACEBOOK']=True
		context['FACEBOOK_API_KEY']=psware.settings.FACEBOOK_API_KEY
		sigs=list(request.GET.items())
		sigStr=''
		for i in range(0, len(sigs)):
			if i!=len(sigs)-1:
				sigStr=sigStr+sigs[i][0]+'='+sigs[i][1]+'&'
			else:
				sigStr=sigStr+sigs[i][0]+'='+sigs[i][1]
		context['FB_SIG']=sigStr
	else:
		context['IN_FACEBOOK']=False
	
	return context
