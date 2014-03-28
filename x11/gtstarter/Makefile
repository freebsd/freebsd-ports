# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	gtstarter
PORTVERSION=	0.4.6.3
PORTREVISION=	6
CATEGORIES=	x11 gnome
MASTER_SITES=	http://webonaut.com/distfiles/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Start gnome-terminal from a list of configured profiles (incl. Applet)

USES=		tar:bzip2
USE_PYTHON=	yes
USE_GNOME=	pygnome2 pygnomeextras gnomeprefix

do-build:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/*.py ${WRKSRC}/*.server
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/
	${INSTALL_SCRIPT} ${WRKSRC}/*.py* \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/*.server \
		${STAGEDIR}${PREFIX}/libdata/bonobo/servers/
	${LN} -sf ${PREFIX}/libexec/${PORTNAME}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
