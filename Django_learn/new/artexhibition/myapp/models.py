from django.db import models

# Create your models here.
class Service(models.Model):
    new_title = models.CharField(max_length=500)
   