from django.db import models


# Create your models here.
class Service(models.Model):
    sevice_icon = models.CharField(max_length=50)
    service_title = models.CharField(max_length=50)
    service_des = models.TextField()

class Products(models.Model):
    product_name = models.CharField(max_length=50)
    status = models.CharField(max_length=50)
    description = models.TextField()