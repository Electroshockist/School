var reloadOnClick = false;

//turns overlay on
function overlayon(text, fontsize) {
  document.getElementById("overlay_text").style.fontSize = fontsize;
  document.getElementById("overlay_text").innerHTML = text;
  document.getElementById("overlay").style.display = "block";
}

//turns overlay off, reloads page if someone won
function overlayoff(){
  //restes font size
  document.getElementById("overlay_text").style.fontSize = "48px";
  //reloads page
  if(reloadOnClick) location.reload();
  //turns overlay off
  else document.getElementById("overlay").style.display = "none";
}
