window.onload = function () {
    var box = document.getElementById('pic');
    var photo_list = box.getElementsByTagName('li');
    var position = [];
    var i = 0;
    for (i = 0; i < photo_list.length; i++) {
        position[i] = { left: photo_list[i].offsetLeft, top: photo_list[i].offsetTop };
    }
    for (i = 0; i < photo_list.length; i++) {
        photo_list[i].style.left = position[i].left + 'px';
        photo_list[i].style.top = position[i].top + 'px';
        photo_list[i].style.position = 'absolute';
        photo_list[i].style.margin = '0';
        photo_list[i].index = i;
    };

    for (i = 0; i < photo_list.length; i++) {
        setDrag(photo_list[i]);
    };

    function setDrag(obj) {
        obj.onmousedown = function (ev) {
            var disX = ev.clientX - obj.offsetLeft;
            var disY = ev.clientY - obj.offsetTop;
            document.onmousemove = function (ev) {
                obj.style.left = ev.clientX - disX + 'px';
                obj.style.top = ev.clientY - disY + 'px';
                for (i = 0; i < photo_list.length; i++) {
                    photo_list[i].className = "";
                };
            };
            document.onmouseup = function () {
                document.onmousemove = null;
                document.onmouseup = null;
            };
            clearInterval(obj.timer);
            return false;
        };
    }
}