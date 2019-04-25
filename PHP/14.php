<!DOCTYPE html>
<html>

<head>
    <title>Validate Email</title>
    <script>
        <?php
            $valid=false;
            $error="";
            if(isset($_POST['check'])){
                $valid=true;
                if(empty($_POST['mail'])){
                    $error="Enter a mail";
                    $valid=false;
                }
            }
            ?>

    </script>
</head>

<body>
    <div style="color:white;background:grey;">
        <h1>Valid e-mail</h1>
    </div>

    <div>
        <form method="post">
            Enter email: <input type="text" name="mail">
            <span style="color:red;">
                <?php
                if(!$valid){
                    echo $error;
                }
                ?>
            </span>
            <input type="submit" name="check">
        </form>
    </div>
    <div>
        <?php
			if($valid)
			{
				$email = $_POST["mail"];
					if(preg_match("/^[a-zA-Z0-9._-]+@[a-zA-Z0-9]+\.[a-zA-Z.]{2,5}$/",$email))
					echo "<b>$email is a valid email</b><br>";
				else 
					echo "<b>$email is not a valid email</b><br>";
			}
		?>
    </div>
</body>

</html>
