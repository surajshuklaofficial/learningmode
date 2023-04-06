from django.shortcuts import render

def ticketNo(request, ticketNo):
    return render(request, 'demo.html')

def tickets(request):
    return render(request, 'tickets.html')

def ticket_details(request):
    return render(request, 'ticket-details.html')
 
def shows_events(request):
    return render(request, 'shows-events.html')

def rent_venue(request):
    return render(request, 'rent-venue.html')

def event_details(request):
    return render(request, 'event-details.html')

def about(request):
    return render(request, 'about.html')

def home(request):
    return render(request, 'index.html')

