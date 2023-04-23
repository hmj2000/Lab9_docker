
function Paragraph_Color() 
{
    // Create variables to gather values for each variables from html text boxes
    var border_R = document.getElementById("border_R").value;
    var border_G = document.getElementById("border_G").value;
    var border_B = document.getElementById("border_B").value;
    var border_width = document.getElementById("border_width").value;
    var bg_R = document.getElementById("bg_R").value;
    var bg_G = document.getElementById("bg_G").value;
    var bg_B = document.getElementById("bg_B").value;

    var tag = document.getElementById("paragraph");
    

    if (border_R >= 0 && border_R <= 255 && border_R !== "") // If within the correct ranges move onto the next if statement otherwise go to the else stament to send an alter that the value is not within the correct ranges
    {
        if (border_G >= 0 && border_G <= 255 && border_R !== "") // If within the correct ranges move onto the next if statement otherwise go to the else stament to send an alter that the value is not within the correct ranges
        {
            if (border_B >= 0 && border_B <= 255 && border_R !== "") // If within the correct ranges move onto the next if statement otherwise go to the else stament to send an alter that the value is not within the correct ranges
            {
                if (border_width !== "") // If within the correct ranges move onto the next if statement otherwise go to the else stament to send an alter that the value is not within the correct ranges
                {
                    if (bg_R >= 0 && bg_R <= 255 && border_R !== "") // If within the correct ranges move onto the next if statement otherwise go to the else stament to send an alter that the value is not within the correct ranges
                    {
                        if (bg_G >= 0 && bg_G <= 255 && border_R !== "") // If within the correct ranges move onto the next if statement otherwise go to the else stament to send an alter that the value is not within the correct ranges
                        {
                            if (bg_B >= 0 && bg_B <= 255 && border_R !== "") // If within the correct ranges move onto the next if statement otherwise go to the else stament to send an alter that the value is not within the correct ranges
                            {
                                // All values are in the correct ranges so now we can follow the users values
                                tag.style.borderColor = `rgb(${border_R},${border_G},${border_B})`;
                                tag.style.borderWidth = border_width
                                tag.style.backgroundColor = `rgb(${bg_R},${bg_G},${bg_B})`;
                            }

                            else // bg_B has the wrong limit
                            {
                                alert("Background B is NOT in between 0 and 255 or is empty")
                            }
                        }

                        else // bg_G has the wrong limit
                        {
                            alert("Background G is NOT in between 0 and 255 or is empty")
                        }
                    } 

                    else // bg_R has the wrong limit
                    {
                        alert("Background R is NOT in between 0 and 255 or is empty")
                    }  
                }

                else // border_width has the wrong limit
                {
                    alert("Border Width is empty")
                }
            }

            else // border_B has the wrong limit
            {
                alert("Border B is NOT in between 0 and 255 or is empty")
            }
        }  

        else // border_G has the wrong limit
        {
            alert("Border G is NOT in between 0 and 255 or is empty")
        } 
    }

    else // border_R has the wrong limit
    {
        alert("Border R is NOT in between 0 and 255 or is empty")
    }
}