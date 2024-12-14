console.time("FirstWay");

function getPrimeNumber() {
    let flag = true;
    while(flag == true) {
        let n = Math.floor(Math.random() * (2_000 - 1) + 2);
        if(n % 2 === 0) continue;
        let arr = [];
        for(let i = 0; i <= Number(n**0.5); i++) {
            if(n % i == 0) {
                arr.push(n / i);
                arr.push(i);
            }
        }
        if(arr.length == 2) {
            flag = false;
            return n;
        }
    }
}
function getPrimitiveRoot(mod) {
    let num = Number(mod) - 1;
    let arr = [];
    for(let i = 2; i <= Math.sqrt(num); i++){
        if(num % i === 0) {
            arr.push(i);
            arr.push(num / i);
        }
    }
    let set = new Set(arr);

    for(let g = 2; g < Number(mod); g++){
        let isPrimitive = true;
        for(let delit of set) {
            let check =  num / delit;
            if( (Math.pow(g,check)) % (Number(mod)) === 1){
                isPrimitive = false;
                break;
            }
        }

        if(isPrimitive) return g;
    }
}
// Генерируем общие данные (простое число и первообразный корень по модулю простого числа)

let primeNumber = BigInt(getPrimeNumber());
let g = BigInt(getPrimitiveRoot(Number(primeNumber)));
let secretKeyA = BigInt(Math.floor(Math.random() * (2_000 - 1) + 1))
let publickKeyA = (g**secretKeyA) % primeNumber;

// Генерируем секретный ключ и общий ключ для пользователя A 

// Генерируем секретный ключ и общий ключ для пользователя B
let secretKeyB =  BigInt(Math.floor(Math.random() * (2_000 - 1) + 1))
let publickKeyB = (g**secretKeyB) % primeNumber;
console.log("\n ===== Общие данные для двух собеседников:\n",
    "Простое число:",primeNumber,"\n",
    "Первообразный корень по модулю:",g,'\n',
    "===== Данные собеседника A:\n",
    "Секретный ключ:", secretKeyA,'\n',
    "Публичный ключ:",publickKeyA,'\n',
    "===== Данные собеседника B:\n",
    "Секретный ключ:", secretKeyB,'\n',
    "Публичный ключ:",publickKeyB,'\n'
)
// Получаем общие ключи для каждого из пользователя

let fullKeyA = (publickKeyB**secretKeyA) % primeNumber;
let fullKeyB = (publickKeyA**secretKeyB) % primeNumber;

console.log("\nПолный ключ собеседника A:", fullKeyA, "\nПолный ключ собеседника B:",fullKeyB)

console.timeEnd("FirstWay");