from django.db import models
from tinymce.models import HTMLField
from autoslug import AutoSlugField

class News(models.Model):
    news_title = models.CharField(max_length=100) # these are fields
    news_desc = HTMLField() # tinymce editor integration in django app

    news_slug = AutoSlugField(populate_from = "news_title", unique = True, null = True, default = None) # unique - does not make same slug, null - it can be null
    # Create your models here.
