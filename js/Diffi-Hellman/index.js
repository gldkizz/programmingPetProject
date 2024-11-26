"use strict"

console.time("FirstWay");
function getPrimeNumber() {
    let flag = false;
    while(flag == false) {
        let n = Math.floor(Math.random() * (2000 - 1) + 1);
        let arr = [];
        for(let i = 0; i < Number(n**0.5) + 1; i++) {
            if(n % i == 0) {
                arr.push(n / i);
                arr.push(i)
            }
        if(arr.length == 2) {
            flag == true
            return n;
        }
        }
    }
}
function getPrimitiveRoot(mod) {
    let num = Number(mod) - 1;
    let arr = new Set();

    for(let i = 2; i <= Math.sqrt(num); i++){
        if(num % i === 0) {
            arr.add(i);
            arr.add(num / i);
        }
    }

    for(let g = 2; g < Number(mod); g++){
        let isPrimitive = true;

        for(let delit of arr) {
            if( Math.pow(g, num / delit) % Number(mod) === 1){
                isPrimitive = false;
                break;
            }
        }

        if(isPrimitive){
            return g;
        }
    }
    return null;
}
// Общие данные
let primeNumber = BigInt(getPrimeNumber());
let g = getPrimitiveRoot(Number(primeNumber));
console.log(g)

// let secretKeyA =  BigInt(Math.floor(Math.random() * (2000 - 1) + 1))
// let secretKeyB =  BigInt(Math.floor(Math.random() * (2000 - 1) + 1))

// let publickKeyA = (g**secretKeyA) % primeNumber;
// let publickKeyB = (g**secretKeyB) % primeNumber;

// let fullKeyA = (publickKeyB**secretKeyA) % primeNumber;
// let fullKeyB = (publickKeyA**secretKeyB) % primeNumber;

// console.log(Number(fullKeyB), Number(fullKeyA))
// console.timeEnd("FirstWay");

// let secretKeyA = BigInt(Math.floor(Math.random() * (100 - 1) + 1));
// let secretKeyB
// let g = 11n;
// let primeNumber = 839n;
// let publicKeyA = g**secretKeyA % primeNumber;