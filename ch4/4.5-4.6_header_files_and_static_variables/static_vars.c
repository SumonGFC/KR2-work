/* This file only contains notes about the "static" keyword from section 4.6 in
 * the book.
 *
 * The "static" declaration, may be applied to external variables or functions.
 * When applied, this will limit the scope of the external var/function to the
 * source file, and will be inaccessible to other linked source files.
 *
 * Thus, there will be no name conflicts with symbols of the same name defined
 * in other source files.
 *
 * It can be applied to both external variables and functions. When applied to
 * functions, the function will only be accessible from its declaration to the
 * end of the source file (and no where else). Normally, functions are always
 * globally accessible across the entire source.
 *
 * "static" can also be applied to local/internal varibales:
 *      - Regular (automatic) variables are created and destroyed during and
 *      after the execution of a subroutine (i.e. function call).
 *
 *      - Conversely, internal static variables are created on the first
 *      function call, but persist after the function finishes executing, and on
 *      subsequent calls these static variables will retain their state from the
 *      end of the last function call.
 */

 void foo(void)
{
        static int counter = 0;
        counter++;
}

int main(void)
{
        foo();  // counter == 0
        foo();  // counter == 1
        foo();  // counter == 2
        foo();  // counter == 3

}
