<!DOCTYPE>
<html>

<head>
    <title>
        REGISTER
    </title>
    <link href="body.css" type="text/css" rel="stylesheet">
    <script>
        <?php
        
            session_start();
            if($_SESSION['loggedin']){
                header("location: welcome.php");
            }
        
            $server="localhost";
            $dbusername="root";
            $dbpassword="";
            $conn = new mysqli($server,$dbusername,$dbpassword,"login1");
            
            $username=$password="";
            $username_err=$password_err=$confirm_pass_err="";
            $valid=false;
            if(isset($_POST['registerButton'])){
                $valid=true;
                if(empty(trim($_POST['username']))){
                    $valid=false;
                    $username_err="Username cannot be empty";
                }else{
                    $username = $_POST['username'];
                    $sql_select = "SELECT USERNAME FROM USERS WHERE USERNAME='$username'";
                    
                    $result = $conn->query($sql_select);
                    if($result->num_rows==1){
                        $username_err = "Username Exists";
                        $valid=false;
                    }
                }
                
                if(empty($_POST['password'])){
                    $valid=false;
                    $password_err="Password cannot be empty";
                }
                   
                if(empty($_POST['confirm_pass'])){
                    $valid=false;
                    $confirm_pass_err="This field cannot be empty";
                }
                   
                if($_POST['password']!=$_POST['confirm_pass']){
                    $valid=false;
                    $confirm_pass_err="Password do not match";
                }else{
                    $password = $_POST['password'];
                }
            }
            ?>

    </script>

</head>

<body>
    <div style="color:white;background:green;">
        <h1>Register</h1>
    </div>

    <div>
        <form method="post">
            <label for="username">Username:</label>
            <input type="text" name="username"><span class="error"><?php if(!$valid) echo $username_err; ?></span><br />
            <label for="password">Password:</label>
            <input type="password" name="password"><span class="error"><?php if(!$valid) echo $password_err; ?></span><br />
            <label for="confirm_pass">Confirm password:</label>
            <input type="password" name="confirm_pass"><span class="error"><?php if(!$valid) echo $confirm_pass_err; ?></span><br />
            <input type="submit" value="Register" name="registerButton">
        </form>
    </div>

    <div>
        <?php
        if($valid){
            
            $sqlInsert = "INSERT INTO USERS(USERNAME,PASSWORD) VALUES ('$username','$password')";
            if($conn->query($sqlInsert)===TRUE){
                echo "<br/> Registeration successful";
                $_SESSION['username']=$username;
                $_SESSION['password']=$password;
                $_SESSION['loggedin']=true;
                header("location: welcome.php");
            }
            else
                echo "<br/>".$conn->error;
            
            $conn->close();
        }
        ?>
    </div>
</body>

</html>
