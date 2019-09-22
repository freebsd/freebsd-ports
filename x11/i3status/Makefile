# $FreeBSD$

PORTNAME=	i3status
PORTVERSION=	2.13
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/i3status/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Small program for generating a status bar

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfuse.so:devel/libconfuse \
		libyajl.so:devel/yajl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_path_PATH_ASCIIDOC=${TRUE} \
		ac_cv_path_PATH_XMLTO=${TRUE} \
		--disable-dependency-tracking
USES=		gmake pkgconfig tar:bzip2
BUILD_WRKSRC=	${WRKSRC}/${CONFIGURE_TARGET}
INSTALL_WRKSRC=	${WRKSRC}/${CONFIGURE_TARGET}

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/i3status.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/i3status.conf \
		${STAGEDIR}${PREFIX}/etc/i3status.conf.sample

.include <bsd.port.mk>
