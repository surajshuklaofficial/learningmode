from django.http import HttpResponse
from django.shortcuts import render

def Homepage(request):
    data = {
        'title' : 'Homepage',
        'name' : 'lakhan2',
        'skills' : ['django', 'video editing', 'DL'],
        'student_details': [
        {'name' : 'pradeep', 'phone' : 84985765483},
        {'name' : 'testing', 'phone' : 93485748394}
        ],
        'numbers' : [10, 20, 30, 40, 50, 60]
    }
    return render(request, 'index.html', data )

def aboutUS(request):
    return HttpResponse('helloworld')

def skills(request):
    return HttpResponse('Welcome to my website')

def skillDetail(request,skillid):
    return HttpResponse(f'skills-{skillid}') 