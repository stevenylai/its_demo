import os
import sys

os.environ['DJANGO_SETTINGS_MODULE'] = 'psware.settings'

sys.path.append('C:/devel/src/wsn/psware')
import django.core.handlers.wsgi

application = django.core.handlers.wsgi.WSGIHandler()


