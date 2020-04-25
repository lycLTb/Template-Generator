$(document).ready(function (){
	$("pre").prepend("<a class=\"copy-button\">Copy</a>");
	$(".copy-button").click(function() {
		var element = $(this).siblings("code");
		var text = $(element).text();
		var $temp = $("<textarea>");
		$("body").append($temp);
		$temp.val(text).select();
		document.execCommand("copy");
		$temp.remove();
		$(this).text("Succeed");

		var e = this;
		setTimeout(function() {
			$(e).text("Copy");
		}, 500);
	});
});