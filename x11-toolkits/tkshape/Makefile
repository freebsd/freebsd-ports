# New ports collection makefile for:	TkShape
# Date created:				13 March 2004
# Whom:					nivit@users.sourceforge.net
#
# $FreeBSD$

PORTNAME=		tkshape
PORTVERSION=		0.4
CATEGORIES=		x11-toolkits
MASTER_SITES=		http://www.cs.man.ac.uk/~fellowsd/tcl/
DISTNAME=		shape${PORTVERSION:S/.//g}

MAINTAINER=		nivit@users.sourceforge.net
COMMENT=		A Tk library to access to X Shaped Window Extension

LIB_DEPENDS=		tk84.1:${PORTSDIR}/x11-toolkits/tk84

PLIST_SUB=		PORTNAME="${PORTNAME}"

INSTALLS_SHLIB=		yes

OPTIONS=		MANPAGES "Install manual pages" on

.include <bsd.port.pre.mk>

.if defined(WITH_MANPAGES)
MAN3=			CombShape.3 QuryShape.3
MANN=			shape.n
.endif

WRKSRC=			${WRKDIR}/${PORTNAME:C/^tk//1}${PORTVERSION}

TCL_VER?=		8.4
TK_VER?=		8.4
WISH?=			wish${TK_VER}

USE_GMAKE=		yes
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-tclconf=${LOCALBASE}/lib/tcl${TCL_VER} \
			--with-tkconf=${LOCALBASE}/lib/tk${TK_VER}
CONFIGURE_WRKSRC=	${WRKSRC}/unix
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}

WHERE_REPLACE=		${WRKSRC}/demos
REPLACE_FILES=		${WHERE_REPLACE}/dragger.tcl \
			${WHERE_REPLACE}/fancytext.tcl \
			${WHERE_REPLACE}/fingerprint.tcl

post-patch: .SILENT
	for FILE in ${REPLACE_FILES}; do \
		${REINPLACE_CMD} -e "/%%WISH%%/s//${WISH:S/\//\\\//g}/g" \
		$${FILE}; \
	done;
	${REINPLACE_CMD} -E 's,(^CFLAGS = )-g,\1${CFLAGS},' \
		${BUILD_WRKSRC}/Makefile.in

FIND_DIRS=		-type d \! -empty
FIND_DEMOS=		demos -type f -and -name "*.tcl" -maxdepth 1
FIND_IMAGES=		demos/images -type f \
			-and \( -name "*.gif" -or -name "*.xbm" \
			-or -name "*.cur" \)

TARGET_DIR=		${PREFIX}/lib/${PORTNAME}
MANPAGES=		${MAN3} ${MANN}

do-install:
# script, library
	cd ${WRKSRC}; \
	${MKDIR} ${TARGET_DIR}/demos; \
	FILES=$$(${FIND} ${FIND_DEMOS}); \
	for FILE in $${FILES}; do \
		${INSTALL_SCRIPT} $${FILE} ${TARGET_DIR}/$${FILE}; \
	done; \
	${INSTALL_SCRIPT} unix/libshape04.so.1.0 ${TARGET_DIR}/libshape04.so.1;

# images, pkgIndex.tcl
	cd ${WRKSRC}; \
	${MKDIR} ${TARGET_DIR}/demos/images; \
	FILES=$$(${FIND} ${FIND_IMAGES}); \
	for FILE in $${FILES}; do \
		${INSTALL_DATA} $${FILE} ${TARGET_DIR}/$${FILE}; \
	done; \
	${INSTALL_DATA} unix/pkgIndex.tcl ${TARGET_DIR}/pkgIndex.tcl;

# manpages
.if defined(WITH_MANPAGES)
	cd ${WRKSRC}; \
	for m in ${MANPAGES} ; do \
	    s=$${m##*.}; \
	    ${INSTALL_MAN} doc/$${m} ${MANPREFIX}/man/man$${s}/$${m}; \
	done;
.endif

.include <bsd.port.post.mk>
