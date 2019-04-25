<!DOCTYPE html>
<html>

<head>
    <title>Compare three numbers</title>
    <link rel="stylesheet" href="body.css" type="text/css">
    <style>
        .error {
            color: red;
        }

        .header {
            background: green;
            color: white;
        }

    </style>
    <script>
        <?php
            $error1="";
            $error2="";
            $error3="";
            $valid=false;
        if(isset($_GET['button'])){
            $valid=true;
            if(empty($_GET['a'])&&$_GET['a']!=0){
                $error1="Enter a value";
                $valid=false;
            }else if(!is_numeric($_GET['a'])){
                $error1="Enter a integer";
                $valid=false;
            }
            if(empty($_GET['b'])&&$_GET['b']!=0){
                $error2="Enter a value";
                $valid=false;
            }else if(!is_numeric($_GET['b'])){
                $error2="Enter a integer";
                $valid=false;
            }
            if(empty($_GET['c'])&&$_GET['c']!=0){
                $error3="Enter a value";
                $valid=false;
            }else if(!is_numeric($_GET['c'])){
                $error3="Enter a integer";
                $valid=false;
            }
        }
        ?>

    </script>
</head>

<body>
    <div class="header">
        <h1>Compare Three numbers</h1>
    </div>

    <div>
        <form method="get">
            Enter a:<input type="text" name="a" value="<?php if($valid) echo $_GET['a'];?>">
            <span class="error">
                <?php
                if(!$valid){
                    echo $error1;
                }
            ?>
            </span><br />
            Enter b:<input type="text" name="b" value="<?php if($valid) echo $_GET['b'];?>">
            <span class="error">
                <?php
                if(!$valid){
                    echo $error2;
                }
            ?>
            </span><br />
            Enter c:<input type="text" name="c" value="<?php if($valid) echo $_GET['c'];?>">
            <span class="error">
                <?php
                if(!$valid){
                    echo $error3;
                }
            ?>
            </span><br />
            <input type="submit" value="Comapare" name="button">
        </form>
    </div>
    <div>
        <?php
        if(isset($_GET['button']) && $valid){
            $a = $_GET['a'];
            $b = $_GET['b'];
            $c = $_GET['c'];
            
            if($a>$b && $a>$c)
                echo $a;
            else if($b>$a && $b>$c)
                echo $b;
            else
                echo $c;
            
            echo " is the largest in $a,$b,$c";
        }
    ?>
    </div>
</body>

</html>
