
function username_value(){
  
  if ( event.keyCode >= 48 & event.keyCode <= 57){
    event.returnValue = false;
  }
  else {
    event.returnValue = true;
    showHint( myForm.username.value );
  }
}

function password_value(){
  var x = myForm.password.value.charAt(0);
  if (!(/^[a-zA-Z]/.test(x)) & x != ""){
      alert("First character must be a letter!");
      myForm.password.value = "";
  }  
}

function showHint(str){
  var xmlhttp;
  if (str.length==0){
    document.getElementById("txtHint").innerHTML="";
    return;
  }
  if (window.XMLHttpRequest){// IE7+,Firefox,Chrome,Opera, Safari
    xmlhttp=new XMLHttpRequest();
  }
  else{// code for IE6, IE5
    xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  }
  xmlhttp.onreadystatechange=function(){
  if (xmlhttp.readyState==4 && xmlhttp.status==200){
    document.getElementById("txtHint").innerHTML=xmlhttp.responseText;
  }
  }
  xmlhttp.open("GET","http://www.cs.bgu.ac.il/~luts/suggest.php?q="+str,true);
  xmlhttp.send();
}

function validate_form(){
  var username = myForm.username.value;
  var password = myForm.password.value;
  if ( username == "" ){
  alert("Username must not be emtpy");
    return;
  }
  else if ( password == "" ){
    alert("Password must not be emtpy");
    return; 
  } 

  else if ( password.length < 4 ){
    alert("Password must be at least 4 characters"); 
    return; 
  }
  else{
    document.getElementById("after_submit").textContent = "You are logged in as: " + username;
  }
}