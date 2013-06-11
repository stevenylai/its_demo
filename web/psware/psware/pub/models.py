from django.db import models

# Create your models here.
class EventMeta (models.Model):
	eventName = models.CharField(max_length=50)
	def __unicode__(self):
		return "Event: "+str(self.eventName)
class EventMetaAttribute (models.Model):
	subID = models.ForeignKey(EventMeta)
	attributeName = models.CharField(max_length=100)
	def __unicode__(self):
		return "Attribute: "+self.attributeName
class EventInstance (models.Model):
	subID = models.ForeignKey(EventMeta)
	pubTime = models.DateTimeField()
	def __unicode__(self):
		return "Event Instance: "+self.subID.eventName
class EventInstanceAttribute (models.Model):
	instanceID = models.ForeignKey(EventInstance)
	attributeID = models.ForeignKey(EventMetaAttribute)
	value = models.IntegerField()
	def __unicode__(self):
		return "Event Instance: "+self.instanceID.subID.eventName\
		+", Attribute ("+self.attributeID.attributeName+"): "+str(self.value)
