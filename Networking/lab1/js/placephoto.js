
var pic = document.getElementById('pic')
var frag = document.createDocumentFragment()
for(let i = 0; i < 10; i++) {
    var li = document.createElement('li')
    li.innerHTML = `<img data-index="${i}" src="./img/photo/pic${i+1}.jpeg" alt="">`
    frag.appendChild(li)
}
pic.appendChild(frag)
var lis_all = pic.children
var screen_width = document.documentElement.clientWidth - 200
var screen_height = document.documentElement.clientHeight - 300

for (let i = 0; i < lis_all.length; i++) {
    var single_li = lis_all[i]
    single_li.style.transform = `rotate(${360}deg)`
    single_li.style.left = Math.random() * screen_width + 'px'
    single_li.style.top = Math.random() * screen_height + 100 + 'px'
}