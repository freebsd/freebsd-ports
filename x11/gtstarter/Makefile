# New ports collection makefile for:	gtstarter
# Date created:				15 April 2004
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	gtstarter
PORTVERSION=	0.2
CATEGORIES=	x11 gnome
MASTER_SITES=	http://webonaut.com/distfiles/${PORTNAME}/

MAINTAINER=	klammer@webonaut.com
COMMENT=	Start gnome-terminal with a specified profile

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_GNOME=	pygnome2

do-build:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' \
		${WRKSRC}/*.py
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${X11BASE}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${X11BASE}/libexec/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.py* \
		${X11BASE}/libexec/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${X11BASE}/share/gnome/applications/
	@${LN} -sf ${X11BASE}/libexec/${PORTNAME}/${PORTNAME} \
		${X11BASE}/bin/${PORTNAME}

.include <bsd.port.mk>
