# New ports collection makefile for:	DockApp Library
# Date created:		17 July 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdockapp
PORTVERSION=	0.6.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://solfertje.student.utwente.nl/~dalroi/libdockapp/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard library for Window Maker dock apps

WRKSRC=		${WRKDIR}/${PORTNAME:S/^lib//}-${PORTVERSION}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-font --without-examples
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/dockapp
.for file in fonts.alias fonts.dir *.pcf.gz
	${INSTALL_DATA} ${WRKSRC}/fonts/${file} ${PREFIX}/lib/X11/fonts/dockapp
.endfor
.if !defined(NOPORTDOCS)
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
