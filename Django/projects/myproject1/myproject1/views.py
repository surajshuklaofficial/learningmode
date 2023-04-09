from django.shortcuts import render,redirect
from django.http import HttpResponse, HttpResponseRedirect
from .forms import UsersForm
from service.models import Products
from django.core.paginator import Paginator
from contactenquiry.models import contactEnquiry

def home(request):
    return render(request, 'index.html')

def home1(request):
    data = {
        'name' : 'suraj shukla',
        'skills' : ['django', 'video editing', 'DL'],
        'student_details': [
        {'name' : 'pradeep', 'phone' : 84985765483},
        {'name' : 'testing', 'phone' : 93485748394}
        ],
        'numbers' : [10, 20, 30, 40, 50, 60]
    }
    # return HttpResponse('hellowrold')
    return render(request, 'index1.html', data)

def about(request):
    return render(request, 'about.html')

def skills(request, skillid):
    return HttpResponse('hellowrold'+str(skillid)) 

def form_get(request): # use exception handling
    try :
        # n1 = request.GET['num1']
        # n2 = request.GET['num2']
        n1 = int(request.GET.get('num1'))
        n2 = int(request.GET.get('num2'))
        print(n1+n2)

    except:
        pass

    return render(request, 'userform.html',{'output' : n1+n2})

def form_post(request): # use exception handling
    result = 0
    try :
        # n1 = request.POST['num1']
        # n2 = request.POST['num2']
        n1 = int(request.POST.get('num1'))
        n2 = int(request.POST.get('num2'))
        print(n1+n2)
        result = n1+n2
    except:
        pass

    return render(request, 'userform.html',{'output' : result})

def form_post_redirect(request): # use exception handling
    result = 0
    try :
        # n1 = request.POST['num1']
        # n2 = request.POST['num2']
        if request.method != 'GET':
            n1 = int(request.POST.get('num1'))
            n2 = int(request.POST.get('num2'))
            print(n1+n2)
            result = n1+n2

            url = f'/form-output?output={result}'
            return redirect(url)
            return HttpResponseRedirect(url)
    except:
        pass

    return render(request, 'userform.html',{'output' : result})

def form_post_redirect_output(request):
    output = request.GET['output']
    return render(request, 'form-output.html',{'output' : output})

def userform_django_form(request): # use exception handling
    result = 0
    fn = UsersForm()

    try :
        # n1 = request.POST['num1']
        # n2 = request.POST['num2']
        n1 = int(request.POST.get('num1'))
        n2 = int(request.POST.get('num2'))
        print(n1+n2)
        result = n1+n2
    except:
        pass

    return render(request, 'userform_django.html',{'form' : fn, 'output' : result})


def userform_action(request): # use exception handling
    result = 0
    try :
        # n1 = request.POST['num1']
        # n2 = request.POST['num2']
        n1 = int(request.POST.get('num1'))
        n2 = int(request.POST.get('num2'))
        print(n1+n2)
        result = n1+n2
    except:
        pass

    return render(request, 'userform_action.html',{'output' : result})

def submitform(request):
    result = 0
    try :
        # n1 = request.POST['num1']
        # n2 = request.POST['num2']
        n1 = int(request.POST.get('num1'))
        n2 = int(request.POST.get('num2'))
        print(n1+n2)
        result = n1+n2

        return render(request, 'form-output.html', {'output' : result})
    
    except:
        pass

    
    return render(request, 'userform_action.html',{'output' : result})

def calculator(request):
    try : 
        if request.method == 'POST':
            n1 = eval(request.POST['num1'])
            n2 = eval(request.POST['num2'])
            opr = request.POST['opr']

            if opr == '+':
                result = n1 + n2

            elif opr == '-':
                result = n1 - n2

            elif opr == '*':
                result = n1 * n2

            elif opr == '/':
                result = n1 / n2

        data = { 'n1': n1, 'n2':n2, 'output' : result}
    
    except Exception as e:
        result = 'Error'
        data = {'output' : result}
        print(e)

    return render(request, 'calculator.html', data)

def products(request):
    newsid = 0
    productData  = Products.objects.all() # according to the order of input
    # # productData  = Products.objects.get(id = newsid) # to get only one data
    # productData  = Products.objects.all().order_by('product_name') # ascending
    # productData  = Products.objects.all().order_by('-product_name')[:1] # limiting query usig slicing
    # productData  = Products.objects.all().order_by('-product_name') # descending
    # if request.method=="GET":
    #     pn = request.GET.get('product_name')
    #     print(pn)
    #     if pn!=None:
    #         productData = Products.objects.filter(product_name__icontains=pn)

    #     print(productData)
    paginator = Paginator(productData, 2) # 2 - no of data to represent
    page_number = request.GET.get('page')
    ProductDataFinal = paginator.get_page(page_number)
    # data = {
    #     'productData' : productData
    # }
    data = {
        'productData' : ProductDataFinal
    }
    return render(request, 'products2.html', data)


def saveenquiry(request):
    n = ''
    if request.method =="POST":
        name = request.POST.get('name')
        email = request.POST.get('email')
        phone = request.POST.get('phone')
        website = request.POST.get('website')
        message = request.POST.get('message')
        data = contactEnquiry(name = name, email = email, phone = phone, website = website, message = message)

        data.save()
        n = 'Data inserted'
    return render(request, 'contact.html', {'n' : n})