<?php


//suggestions database
$a[]="Anna";
$a[]="Brittany";
$a[]="Cinderella";
$a[]="Diana";
$a[]="Eva";
$a[]="Fiona";
$a[]="Gunda";
$a[]="Hege";
$a[]="Inga";
$a[]="Johanna";
$a[]="Kitty";
$a[]="Linda";
$a[]="Nina";
$a[]="Ophelia";
$a[]="Petunia";
$a[]="Amanda";
$a[]="Raquel";
$a[]="Cindy";
$a[]="Doris";
$a[]="Eve";
$a[]="Evita";
$a[]="Sunniva";
$a[]="Tove";
$a[]="Unni";
$a[]="Violet";
$a[]="Liza";
$a[]="Elizabeth";
$a[]="Ellen";
$a[]="Wenche";
$a[]="Vicky";

//get the q parameter from URL
$q = strtolower($_GET["q"]);

//TODO: lookup all hints from our simple "data base"
$hint="";
if (strlen($q) > 0){
  foreach($a as $hint_name){
    if ( strlen($q) <= strlen($hint_name) ){
      $num = substr_count( strtolower($hint_name), $q, 0, strlen($q));
      if ( $num > 0 ){
	$hint = $hint_name;
	break;
      }
    }
  }
}



// Set output to "no suggestion" if no hint were found
// or to the correct values
if ($hint === "")
  {
  $response="no suggestion";
  }
else
  {
  $response=$hint;
  }

//output the response
echo $response;
?>