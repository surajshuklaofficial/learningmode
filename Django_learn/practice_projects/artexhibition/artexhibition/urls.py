"""artexhibition URL Configuration

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
    path('event-details.html', views.event_details),
    path('ticket-details.html', views.tickets_details),
    path('tickets.html', views.tickets),
    path('shows-events.html', views.shows_events),
    path('rent-venue.html', views.rent_venue),
    path('about.html', views.about),
    path('index.html', views.home),
    path('', views.home),
    path('admin/', admin.site.urls),
]