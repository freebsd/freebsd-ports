# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Alien-wxWidgets
PORTVERSION=	0.65
PORTREVISION=	1
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	Perl5 module for building, finding and using wxWidgets binaries

USES=		perl5 compiler:env
USE_PERL5=	modbuild
USE_WX=		3.0
WX_COMPS=	wx
WX_UNICODE=	yes
WX_UNI=		uni_
CONFIGURE_ARGS+=	--wxWidgets-build=0 --wxWidgets-unicode=1

WX_UVER!=	${MAKE} -C ${.CURDIR}/../../x11-toolkits/wxgtk30 -V'$${PORTVERSION:C/\./_/g}'
PLIST_SUB+=	WX_UVER=${WX_UVER} WX_UNI=${WX_UNI}

post-patch:
	@${REINPLACE_CMD} -e 's/wx-config/${WX_CONFIG:T}/' ${WRKSRC}/Build.PL
	@${REINPLACE_CMD} -e "s/\'wx-config/\'${WX_CONFIG:T}/" -e "s/lc_r/lpthread/" \
		${WRKSRC}/inc/My/Build/Any_wx_config.pm

.include <bsd.port.mk>
