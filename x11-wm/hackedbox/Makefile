# New ports collection makefile for:	hackedbox
# Date created:				2002-05-11
# Whom:				Dominic Marks <dominic_marks@btinternet.com>
# based on the blackbox and openbox ports
#
# $FreeBSD$
#

PORTNAME=	hackedbox
PORTVERSION=	0.7.0
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://scrudgeware.org/

MAINTAINER=	dominic_marks@btinternet.com

MAN1=		hackedbox.1 hsetroot.1
DOCS=		AUTHORS ChangeLog ChangeLog-0.40.x ChangeLog-0.50.x \
			ChangeLog-0.51.x ChangeLog-0.60.x ChangeLog-0.62.x \
			ChangeLog-0.7.0 ChangeLog.bsetbg INSTALL LICENSE \
			README README.bbtools README.bsetbg TODO hackbox.pws
I10L=		C da_DK de_DE es_ES et_EE fr_FR it_IT nl_NL pt_BR ru_RU sl_SI \
			sv_SE tr_TR
BACKGROUNDS=	Abominations.jpg Adrift.jpg Minus_thirty-five.jpg blackngrey.jpg
STYLES=		Artwiz Cthulhain Flux Minimal Nyz Operation Outcomes Rampage \
			Rancor Results Shade Spiff TDF Twice
PLIST=		${WRKDIR}/pkg-plist
#USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

do-patch:
	${PERL} -pi -e \
		"s:/usr/local/share/hackedbox:${PREFIX}/share/hackedbox:g" \
		${WRKSRC}/data/menu.in
	${PERL} -pi -e \
		"s:blackbox:hackedbox:g; s:Blackbox:Hackedbox:g; \
		s:bsetroot:hsetroot:g; s:Bsetroot:Hsetroot:g" \
		${WRKSRC}/data/styles/* ${WRKSRC}/doc/*.1 \
		${WRKSRC}/doc/ja_JP/*.1 ${WRKSRC}/doc/nl_NL/*.1 \
		${WRKSRC}/doc/sl_SI/*.1
pre-install:
	${RM} -f ${PLIST}
.for ii in hsetroot hackedbox
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} share/hackedbox/menu >> ${PLIST}
.for ii in POSIX US_ASCII de en en_US es fr it nl
	${ECHO_CMD} share/hackedbox/nls/${ii} >> ${PLIST}
.endfor
.for ii in ${I10L}
	${ECHO_CMD} share/hackedbox/nls/${ii}/hackedbox.cat >> ${PLIST}
	${ECHO_CMD} @dirrm share/hackedbox/nls/${ii} >> ${PLIST}
.endfor
.for ii in ${BACKGROUNDS}
	${ECHO_CMD} share/hackedbox/backgrounds/${ii} >> ${PLIST}
.endfor
.for ii in ${STYLES}
	${ECHO_CMD} share/hackedbox/styles/${ii} >> ${PLIST}
.endfor
.for ii in /backgrounds /styles /nls /
	${ECHO_CMD} @dirrm share/hackedbox${ii} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for ii in ${DOCS} Hackedbox.xml
	${ECHO_CMD} share/doc/hackedbox/${ii} >> ${PLIST}
.endfor
.for ii in nl_NL/hackedbox.1 nl_NL/hsetroot.1 sl_SI/hackedbox.1
	${ECHO_CMD} share/doc/hackedbox/${ii} >> ${PLIST}
.endfor
.for ii in /nl_NL /sl_SI /
	${ECHO_CMD} @dirrm share/doc/hackedbox${ii} >> ${PLIST}
.endfor
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/util/bsetroot ${PREFIX}/bin/hsetroot
	${INSTALL_PROGRAM} ${WRKSRC}/src/blackbox ${PREFIX}/bin/hackedbox
	${MKDIR} ${DATADIR}/styles ${DATADIR}/backgrounds
	${INSTALL_DATA} ${WRKSRC}/data/menu ${DATADIR}
.for ii in ${I10L}
	${MKDIR} ${PREFIX}/share/hackedbox/nls/${ii}/
	${INSTALL_DATA} ${WRKSRC}/nls/${ii}/blackbox.cat \
		${PREFIX}/share/hackedbox/nls/${ii}/hackedbox.cat
.endfor
	cd ${PREFIX}/share/hackedbox/nls/ && \
		${LN} -fs C POSIX && \
		${LN} -fs C US_ASCII && \
		${LN} -fs C en && \
		${LN} -fs C en_US && \
		${LN} -fs de_DE de && \
		${LN} -fs es_ES es && \
		${LN} -fs fr_FR fr && \
		${LN} -fs it_IT it && \
		${LN} -fs nl_NL nl
.for ii in ${BACKGROUNDS}
	${INSTALL_DATA} ${WRKSRC}/data/backgrounds/${ii} \
		${PREFIX}/share/hackedbox/backgrounds/
.endfor
.for ii in ${STYLES}
	${INSTALL_DATA} ${WRKSRC}/data/styles/${ii} \
		${PREFIX}/share/hackedbox/styles/
.endfor
	${CP} -p ${WRKSRC}/doc/bsetroot.1 ${WRKSRC}/doc/hsetroot.1
	${CP} -p ${WRKSRC}/doc/blackbox.1 ${WRKSRC}/doc/hackedbox.1
	${INSTALL_MAN} ${WRKSRC}/doc/blackbox.1 ${PREFIX}/man/man1/hackedbox.1
	${INSTALL_MAN} ${WRKSRC}/doc/hsetroot.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/ja_JP/blackbox.1 \
		${PREFIX}/man/ja/man1/hackedbox.1
	${INSTALL_MAN} ${WRKSRC}/doc/ja_JP/bsetroot.1 \
		${PREFIX}/man/ja/man1/hsetroot.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/nl_NL ${DOCSDIR}/sl_SI
.for ii in ${DOCS} doc/Hackedbox.xml
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/nl_NL/blackbox.1 \
		${DOCSDIR}/nl_NL/hackedbox.1
	${INSTALL_DATA} ${WRKSRC}/doc/nl_NL/bsetroot.1 \
		${DOCSDIR}/nl_NL/hsetroot.1
	${INSTALL_DATA} ${WRKSRC}/doc/sl_SI/blackbox.1 \
		${DOCSDIR}/sl_SI/hackedbox.1
.endif

.include <bsd.port.mk>
