/* How are declarations written so that variables are properly declared during
 * compilation?
 * 
 * How are declarations arranged so that all the pieces will be properly
 * connected when the program is loaded?
 *
 * How are declarations organized so there is only one copy?
 * How are external variables initialized?
 */

// This file contains only notes about this chapter

/* SCOPE:
 * The scope of LOCAL variables starts at its declaration and ends at the end
 * of the block.
 *
 * With c99+, we CAN declare variables inside loop initializers! Scope of such
 * a variable will be confined to the loop block.
 *
 * The scope of an EXTERNAL variable (not to be confused with an "extern"
 * variable) lasts from the line it is declared to the end of the file.
 *
 * If a function references a function/variable, it must be declared BEFORE the
 * function that references it (not necessarily defined) in the same file.
 *
 * If an external variable is to be referred to before it is defined, or if it
 * is defined in a different source file from the one where it is being used,
 * then an extern declaration is mandatory.
 *
 * Outside of a function (in the global scope), the extern keyword DECLARES
 * (but does not define) a variable -- it indicates that the variable is
 * defined elsewhere.
 *
 * There must be only ONE DEFINITION of an external variable among all the files
 * that make up the source program; other files may contain extern declarations
 * to access it. (There may also be extern declarations in the file containing
 * the definition.)
 *
 * Array sizes must be SPECIFIED WITH THE DEFINITION, but are
 * optional with an extern declaration.
 */
