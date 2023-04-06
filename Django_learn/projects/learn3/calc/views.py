from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def home(request):
    # return HttpResponse('helloworld');
    return render(request, 'home.html',{'name' : 'suraj shukla'})

def add(request):
    val1 = request.GET['num1']
    val2 = request.GET['num2']

    result = val1 + val2
    return render(request, 'result.html', {'result':result})