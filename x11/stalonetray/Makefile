# Created by: Stepan Zastupov [RedChrom] <redchrom@gmail.com>
# $FreeBSD$

PORTNAME=	stalonetray
PORTVERSION=	0.8.3
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	STAnd-aLONE system tray

LICENSE=	GPLv2

USES=		tar:bzip2 xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-native-kde \
		--disable-debug

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO stalonetray.html
PORTEXAMPLES=	stalonetrayrc.sample
PLIST_FILES=	bin/stalonetray man/man1/stalonetray.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for file in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
