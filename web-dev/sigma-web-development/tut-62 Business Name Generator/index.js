function probCal() {
    return Math.floor((Math.random() * 3));
}

function randomChooser(A, B, C) {
    const prob = probCal();

    if (prob === 0) return A
    else if (prob === 1) return B
    else if (prob === 2) return C
    else return randomChooser(A, B, C);
}

function randomNameGenerator() {
    const str1 = randomChooser("Crazy", "Amazing", "Fire");
    const str2 = randomChooser("Engine", "Foods", "Garments");
    const str3 = randomChooser("Bros", "Limited", "Hub");

    return str1 + str2 + str3;
}


setInterval(() => console.log(randomNameGenerator()), 1000);