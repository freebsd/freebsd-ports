# $FreeBSD$

PORTNAME=	rofi-pass
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	alex@xanderio.de
COMMENT=	Rofi frontend for pass

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		gawk:lang/gawk \
		${LOCALBASE}/bin/grep:textproc/gnugrep \
		pass:sysutils/password-store \
		pwgen:sysutils/pwgen \
		qrencode:graphics/libqrencode \
		rofi:x11/rofi \
		xdotool:x11/xdotool

USE_GITHUB=	yes
GH_ACCOUNT=	carnager

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/addpass \
		bin/rofi-pass \
		"@sample etc/rofi-pass.conf.sample"
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/addpass ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/rofi-pass ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/config.example \
		${STAGEDIR}${PREFIX}/etc/rofi-pass.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
