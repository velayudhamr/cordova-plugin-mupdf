#ifndef MUPDF_FITZ_OUTLINE_H
#define MUPDF_FITZ_OUTLINE_H

#include "system.h"
#include "context.h"
#include "link.h"
#include "output.h"

/* Outline */

/*
	fz_outline is a tree of the outline of a document (also known
	as table of contents).

	title: Title of outline item using UTF-8 encoding. May be NULL
	if the outline item has no text string.

	dest: Destination in the document to be displayed when this
	outline item is activated. May be FZ_LINK_NONE if the outline
	item does not have a destination.

	next: The next outline item at the same level as this outline
	item. May be NULL if no more outline items exist at this level.

	down: The outline items immediate children in the hierarchy.
	May be NULL if no children exist.
*/

typedef struct fz_outline_s fz_outline;

struct fz_outline_s
{
	char *title;
	fz_link_dest dest;
	fz_outline *next;
	fz_outline *down;
};

/*
	fz_print_outline_xml: Dump the given outlines as (pseudo) XML.

	out: The file handle to output to.

	outline: The outlines to output.
*/
void fz_print_outline_xml(fz_context *ctx, fz_output *out, fz_outline *outline);

/*
	fz_print_outline: Dump the given outlines to as text.

	out: The file handle to output to.

	outline: The outlines to output.
*/
void fz_print_outline(fz_context *ctx, fz_output *out, fz_outline *outline);

/*
	fz_drop_outline: Free hierarchical outline.

	Free an outline obtained from fz_load_outline.

	Does not throw exceptions.
*/
void fz_drop_outline(fz_context *ctx, fz_outline *outline);

#endif
