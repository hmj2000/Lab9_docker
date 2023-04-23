function Check() // Function to check if passwords are valid and then if they are the same or not
{
    var password1 = document.getElementById("password1").value; // Get the first password value
    var password2 = document.getElementById("password2").value; // Get the second password value


    if (password1.length < 8) { // Checks if password1 is less than 8
        alert("The length of the first password is less than 8 letters!")
    } else if (password2.length < 8) { // Checks if password2 is less than 8
        alert("The length of the second password is less than 8 letters!")
    } else if (password1 != password2) { // Since both are 8+ then we check if they are the not same
        alert("Two passwords don't match!")
    } else { // Since we have apssed all thests they must be the same
        alert("Two passwords do match!")
    }
}

