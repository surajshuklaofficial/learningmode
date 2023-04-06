from django.db import models

# Create your models here.
class Service(models.Model):
    title = models.charField(max_length = 500)