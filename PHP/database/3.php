<!DOCTYPE html>
<html>

<head>
    <title>Login</title>
    <link href="body.css" rel="stylesheet" type="text/css">
    <script>
        <?php
        
        session_start();
        if($_SESSION['loggedin']){
            header("location: welcome.php");
        }
        
        $valid=false;
        $dbusername = "root";
        $dbserver = "localhost";
        $dbpassword = "";
        $db = "login1";
        $conn = new mysqli($dbserver,$dbusername,$dbpassword,$db);
        
        $error = "";
        $username =$password= "";
        $username_err = $password_err = "";
        if(isset($_POST['login'])){
            $valid=true;
            
            if(empty($_POST['username'])){
                $valid=false;
                $username_err = "Username is empty";
            }else{
                $username = trim($_POST['username']);
            }
            
            if(empty($_POST['password'])){
                $valid = false;
                $password_err = "Password is empty";
            }else{
                $password = trim($_POST['password']);
            }
            
            if(empty($username_err)&&empty($password_err)){
                $sql = "SELECT USERNAME,PASSWORD FROM USERS WHERE USERNAME='$username' and PASSWORD='$password'";
                $q = $conn->query($sql);
                
                if($q->num_rows==1){
                    $valid=true;
                }else{
                    $valid=false;
                    $error = "Wrong username or Password";
                }
            }
            $conn->close();
        }
        ?>

    </script>
</head>

<body>
    <div style="color:white;background:green;">
        <h1>Login</h1>
    </div>
    <div>
        <form method="post">
            Username: <input type="text" name="username">
            <span class="error"><?php if(!$valid) echo $username_err; ?></span><br />
            Password: <input type="password" name="password">
            <span class="error"><?php if(!$valid) echo $password_err; ?></span><br />
            <input type="submit" name="login">
        </form>
    </div>
    <div>
        <?php
    if($valid){
        echo "<br/>Login success";
        
        $_SESSION['username']=$username;
                $_SESSION['password']=$password;
                $_SESSION['loggedin']=true;
                header("location: welcome.php");
    }else{
        echo $error;
    }
    ?>
    </div>
</body>

</html>
