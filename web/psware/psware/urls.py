from django.conf.urls import patterns, include, url
from django.contrib import admin
admin.autodiscover()

# Uncomment the next two lines to enable the admin:
# from django.contrib import admin
# admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'psware.views.home', name='home'),
    # url(r'^psware/', include('psware.foo.urls')),
    (r'^((wsn/)?psware/)?', include('psware.common.urls')),
    (r'^((wsn/)?psware/)?sub/', include('psware.sub.urls')),
    (r'^((wsn/)?psware/)?pub/', include('psware.pub.urls')),
    (r'^((wsn/)?psware/)?itransnet/', include('psware.itransnet.urls')),
    (r'^.*static/(?P<path>.*)$', 'django.views.static.serve', {'document_root': 'C:/devel/src/wsn/psware/psware/templates/static'}),
    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    # url(r'^admin/', include(admin.site.urls)),
    (r'^((wsn/)?psware/)?admin/', include(admin.site.urls)),
)
