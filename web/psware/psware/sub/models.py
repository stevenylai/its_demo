from django.db import models

# Create your models here.
class Subscription (models.Model):
	sub = models.CharField(max_length=500)
	version = models.IntegerField()
	subTime = models.DateTimeField()
