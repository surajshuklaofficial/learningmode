# from django.contrib.admin.sites import site
from django.contrib import admin    
from service.models import Service
from service.models import Products

class ServiceAdmin(admin.ModelAdmin):
    list_display = ('service_icon', 'service_title', 'service_des')

class ProductsAdmin(admin.ModelAdmin):
    list_display = ('product_name', 'status', 'description')

admin.site.register(Service)
admin.site.register(Products)
# Register your models here.
