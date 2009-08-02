# New ports collection makefile for:	DockApp Library
# Date created:		17 July 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdockapp
PORTVERSION=	0.6.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://solfertje.student.utwente.nl/~dalroi/libdockapp/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard library for Window Maker dock apps

USE_BZIP2=	yes
USE_XORG=	xext xpm
USE_GNOME=	gnometarget
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--without-font --without-examples
USE_LDCONFIG=	yes

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/dockapp
.for file in fonts.alias fonts.dir *.pcf.gz
	${INSTALL_DATA} ${WRKSRC}/fonts/${file} ${PREFIX}/lib/X11/fonts/dockapp
.endfor
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for file in README
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}/basic
.for file in Imakefile README *.c *.xpm
	${INSTALL_DATA} ${WRKSRC}/examples/basic/${file} ${EXAMPLESDIR}/basic
.endfor
	@${MKDIR} ${EXAMPLESDIR}/rectangles
.for file in Imakefile *.c
	${INSTALL_DATA} ${WRKSRC}/examples/rectangles/${file} ${EXAMPLESDIR}/rectangles
.endfor
.endif

.include <bsd.port.mk>
