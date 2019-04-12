# C_language
Small C programs

--------------------------------------------------Temperature.c---------------------------------------------------------------

The program prompt the user to input the number of days, the high and low for each.

Define and implement highestTemp function with one input parameter “double high[]”
and one parameter “int n” (the number of values in the array)that returns an integer 
that is the index of the cell that has the highest temperature.

Define and implement lowestTemp function with one input parameter “double low[]”
and one parameter “int n” (the number of values in the array) that returns an integer
that is the index of the cell that has the lowest temperature.

Define and implement avgTemp function with three input parameters “const double
low[]” , “const double high[]” and int n representing the number of elements of the
arrays. The function should return a double that is the mean (average) temperature for a
period entered by the user.

--------------------------------------------------sales.c instructions---------------------------------------------------------------

Customers who are younger than 18 are assumed to be students and get a 15% discount off the
base price of the item to be purchased,
Customers older than 65 get a 10% discount off the base price of the item,
Customers who are members of our Buyer’s Club earn a 5% discount based on the original price
of the item,
If customers enter a valid discount code, they can save a % of the original price based on the
discount code they enter. The code SAVE_WIN_19 will save 5% while the code BDAY_SPECIAL
will save 7%. Only one discount code can be entered per customer.
Discounts are all calculated as a percentage of the original item price and the total of all
discounts is subtracted from the original price to yield the taxable amount.
The final price is the total of the taxable amount plus 13% tax.
Shipping is added onto the final price and, in most cases, is calculated as a percentage of the
final price with taxes added. For customers who live in Toronto, we have a flat delivery change
of $5.00. For the rest of Ontario, the cost is $7.00 plus 5% of the final price including taxes.
Elsewhere in Canada the cost is $10.00 plus 10% of the final cost including taxes. For addresses
outside Canada, the cost is $15.00 plus 15% of the final price including taxes.
Items which are on sale are offered at 10% off. When they are printed on the invoice, they will
have one space and an asterisk after their name.
When the address is entered, the program must recognize Canada, Toronto and Ontario with
either upper or lower case for the first letter in the names.

