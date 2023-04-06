from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.

def home(request):
    return HttpResponse("helloworld...");

def add(request):
    val1 = request.GET['num1']
    val2 = request.Get['num2']
    result = val1 + val2
    return render(request, 'result.html', {'result':result})