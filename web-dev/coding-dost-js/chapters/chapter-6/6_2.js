const form = document.querySelector('form');

form.addEventListener('submit', function(e) {
    e.preventDefault();
    console.log(form.email.value); // iff email is id or name then it can accessed like this
})