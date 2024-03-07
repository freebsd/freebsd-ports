PORTNAME=	x-on-resize
PORTREVISION=	1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	x11
PATCH_SITES=	https://gitlab.com/${GL_ACCOUNT}/${PORTNAME}/-/commit/
PATCHFILES=	7caa6ceec64ebb313444eabea7d892d8fee99dd9.patch:-p1 \
		f0490d04c7cb171cd01a91dd51bf15ac4af5addf.patch:-p1 \
		617e5ed8bb6441ed85083881d34af8d7cf3ea7e4.patch:-p1

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Daemon for hotplug and screen reconfigure events of X displays
WWW=		https://gitlab.com/0mp/x-on-resize

LICENSE=	GPLv2

USES=		autoreconf pkgconfig xorg
USE_GITLAB=	yes
GL_ACCOUNT=	0mp
GL_TAGNAME=	f59c9247e682b95f4091def7575490466f131131

USE_XORG=	x11 xorg-macros xrandr

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/x-on-resize \
		share/man/man1/x-on-resize.1.gz

PORTEXAMPLES=	xrandr-auto

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
