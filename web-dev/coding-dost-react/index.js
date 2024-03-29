function childClickHandler() {
    console.log('Child Clicked');
}

document.getElementById('grandparent').addEventListener('click', function () {
    console.log('Grandparent Clicked');
}, true);

document.getElementById('child').addEventListener('click', childClickHandler);

// Debugging: Check if this code is executed
console.log('Event listeners added.');

// Later, remove the event listener
document.getElementById('child').removeEventListener('click', childClickHandler);
console.log('Event listener removed.');
