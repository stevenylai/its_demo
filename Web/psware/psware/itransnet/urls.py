from django.conf.urls.defaults import *

urlpatterns = patterns('psware.itransnet.views',
	(r'^$', 'trafficjamsub'),
	(r'^trafficjampub/$', 'trafficjampub'),
	(r'^test/$', 'test'),
	# Define other pages you want to create here
)

