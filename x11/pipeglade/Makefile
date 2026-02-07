PORTNAME=	pipeglade
PORTVERSION=	4.7.0
PORTREVISION=	6
CATEGORIES=	x11 devel

MAINTAINER=	trebbu@googlemail.com
COMMENT=	Graphical user interface driven by pipes or fifos
WWW=		http://pipeglade.boundp.org

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	trebb

USES=		gettext-runtime gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libxml2

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/clock.sh ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/echo.sh ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/clock.ui ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/pipeglade.ui ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/simple_dialog.ui ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/simple_open.ui ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
