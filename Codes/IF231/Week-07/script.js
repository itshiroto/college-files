$.fn.addCard = function (name, message) {
  let $el = $("<div></div>")
        .append($("<h6></h6>").text(name))
        .append($("<p></p>").text(message))
        .addClass(
          "p-2"
        )
        .css("background-color", "#dde1e4")
  if (name === "Me") 
    $el
      .addClass("text-end")
      .css("background-color", "#c6f2fb")

  $(this).append($el);
}

$("#other-btn").click(function() {
  $("#messages").addCard(
    ($("#other-name").val()),
    ($("#other-msg").val())
  )
});

$("#me-btn").click(function() {
  $("#messages").addCard(
    "Me",
    ($("#me-msg").val())
  )
});


