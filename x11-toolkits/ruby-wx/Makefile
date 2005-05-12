# New ports collection makefile for:	x11-toolkits/ruby-wx
# Date created:				03.01.2004
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	wx
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/1983/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	wxruby-${PORTVERSION:S/.0$//}-src
DIST_SUBDIR=	ruby

MAINTAINER=	q@uni.de
COMMENT=	Ruby bindings for wxWindows (aka wxWidgets)

LIB_DEPENDS=	wx_gtk2-2.4:${PORTSDIR}/x11-toolkits/wxgtk24 \
		wx_gtk2_xrc-2.4:${PORTSDIR}/x11-toolkits/wxgtk24-contrib

USE_ICONV=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BROKEN=		"Cannot link: undefined versioned symbol name"
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/src
DOCS=		README README.linux ChangeLog

post-patch:
	@${FIND} ${WRKSRC} -name *.t | ${XARGS} ${REINPLACE_CMD} -e 's|||'
	@${REINPLACE_CMD} -E 's/ html(processor|window).o//' ${WRKSRC}/depend

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	cd ${RUBY_MODEXAMPLESDIR} && ${MKDIR} `cd ${WRKSRC}/../samples && ${FIND} * -type d`
	for f in `cd ${WRKSRC}/../samples && ${FIND} * -type f`; do \
	  ${INSTALL_DATA} ${WRKSRC}/../samples/$$f ${RUBY_MODEXAMPLESDIR}/$$f; \
	done
.endif

.include <bsd.port.post.mk>
