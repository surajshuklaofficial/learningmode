"""myproject1 URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from . import views

urlpatterns = [
    path('', views.home),
    path('h', views.home1),
    path('about.html', views.about, name = 'about'), # url tagging 
    # path('skills/<str:skill>', views.skillDetail) # dynamic url
    path('<int:skillid>', views.skills), # skillid of url and view.skillDetail's parameter (skillid) must be same, if data is not confirmed --> do not declare data type in advance
    path('admin/', admin.site.urls),
    path('userform-get', views.form_get),
    path('userform-post', views.form_post),
    path('userform-post-redirect', views.form_post_redirect),
    path('form-output', views.form_post_redirect_output),
    path('userform-action', views.userform_action),
    path('submitform', views.submitform, name='submitform'),
    path('userform-django-form', views.userform_django_form),
    path('calculator', views.calculator ),
    path('products.html', views.products)
]
