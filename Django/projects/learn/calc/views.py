from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.

def home(request):
    # return HttpResponse("<h1>hello world1<h1>"); #content as a heading
    return render(request, 'home.html', { "name" : "suraj shukla"})

def add(request):

    # val1 = int(request.GET['num1'])
    # val2 = int(request.GET['num2'])
    val1 = int(request.POST['num1'])
    val2 = int(request.POST['num2'])

    res = val1 + val2

    return render(request, "result.html", {'result':res})